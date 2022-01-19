
#include "csv.h"

namespace csv
{
    /**
     * @brief Decodifica uma linha em formato CSV a partir de um caractere delimitador
     * e exporta a contagem de elementos na linha e a matriz com os elementos decodificados
     * 
     * @param line string contendo a linha CSV a ser decodificada
     * @param delimiter caractere delimitador de colunas
     * @param output matriz contendo as strings de dados decodificados
     * @param count contagem de elementos decodificados (colunas)
     * @return int mesmo que count
     */
    int parseRow(std::string line, const char *delimiter, char *output[], int &count)
    {
        char *cline, *tok;
        cline = (char *)calloc(line.length() + 1, sizeof(char));
        std::strcpy(cline, line.c_str());

        count = 0;
        tok = strtok(cline, delimiter);

        while (tok != NULL)
        {
            output[count] = tok;
            tok = strtok(NULL, delimiter);
            count++;
        }
        return count;
    }

    /**
     * @brief Lê o arquivo CSV, decompõe em linhas e retorna a contagem de linhas totais
     * 
     * @param file stream arquivo a ser decomposto
     * @param output matriz de saída contendo as linhas resultantes
     * @param lcount contagem total de linhas do arquivo
     * @return int mesmo que lcount
     */
    int parseFileRows(std::ifstream *file, std::string output[], int &lcount)
    {
        lcount = 0;
        std::string line;

        while (getline(*file, line))
        {
            output[lcount] = line;
            lcount++;
        }
        return lcount;
    }

    /**
     * @brief Lê o arquivo CSV, decompõe em linhas e retorna a contagem de linhas totais
     * e a linha contendo o cabeçalho (nomes das colunas)
     * 
     * @param file stream arquivo a ser decomposto
     * @param output matriz de saída contendo as linhas resultantes
     * @param header linha contento o cabeçalho
     * @param lcount contagem total de linhas do arquivo
     * @return int mesmo que lcount
     */
    int parseFileRows(std::ifstream *file, std::string output[], std::string *header, int &lcount)
    {
        parseFileRows(file, output, lcount);
        *header = output[0];
        return lcount;
    }

}