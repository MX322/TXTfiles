#include <iostream>
using namespace std;


int CountOfSymb(const char* path);
int CountOfStr(const char* path);
int CountOfGlas(const char* path);
int CountOfSoglas(const char* path);
int CountOfDig(const char* path);


int main()
{
    const char* pathStatist = "E:\\statistics.txt";
    const char* pathText = "E:\\text.txt";

    FILE* statistics;

    int c;
    int symb = 0;

    if (fopen_s(&statistics, pathStatist, "w") != NULL)
    {
        cout << "Error";
    }

    else
    {

        fprintf(statistics, "%s", "symbols: ");
        fprintf(statistics, "%d", CountOfSymb(pathText));

        fprintf(statistics, "%s", "\nstrings: ");
        fprintf(statistics, "%d", CountOfStr(pathText));

        fprintf(statistics, "%s", "\nglas letters: ");
        fprintf(statistics, "%d", CountOfGlas(pathText));

        fprintf(statistics, "%s", "\nsoglas letters: ");
        fprintf(statistics, "%d", CountOfSoglas(pathText));

        fprintf(statistics, "%s", "\ndigits: ");
        fprintf(statistics, "%d", CountOfDig(pathText));
        
    }

}


int CountOfSymb(const char* path)
{
    FILE* TEXT;

    int c;
    int symb = 0;

    if (fopen_s(&TEXT, path, "r") != NULL)
    {
        cout << "Error";
    }

    else
    {
        while (!feof(TEXT))
        {
            c = fgetc(TEXT);
            if (c != ' ' && c != '\n')
            {
                symb++;
            }
        }
    }

    return symb;
}


int CountOfStr(const char* path)
{
    FILE* TEXT;

    int c;
    int str = 0;

    if (fopen_s(&TEXT, path, "r") != NULL)
    {
        cout << "Error";
    }

    else
    {
        while (!feof(TEXT))
        {
            c = fgetc(TEXT);
            if (c == '\n')
            {
                str++;
            }
        }
    }

    return str;
}


int CountOfGlas(const char* path)
{
    FILE* TEXT;

    int c;
    int glas = 0;

    char letters[] = { "aeiouy" };

    if (fopen_s(&TEXT, path, "r") != NULL)
    {
        cout << "Error";
    }

    else
    {
        while (!feof(TEXT))
        {
            c = fgetc(TEXT);

            for (int i = 0; i < strlen(letters); i++)
            {
                if (c == letters[i])
                {
                    glas++;
                }
            }
           
        }
    }

    return glas;
}


int CountOfSoglas(const char* path)
{
    FILE* TEXT;

    int c;
    int soglas = 0;

    char letters[] = { "bcdfghjklmnpqrstvwxyz" };

    if (fopen_s(&TEXT, path, "r") != NULL)
    {
        cout << "Error";
    }

    else
    {
        while (!feof(TEXT))
        {
            c = fgetc(TEXT);

            for (int i = 0; i < strlen(letters); i++)
            {
                if (c == letters[i])
                {
                    soglas++;
                }
            }

        }
    }

    return soglas;
}


int CountOfDig(const char* path)
{
    FILE* TEXT;

    int c;
    int dig = 0;

    char letters[] = { "0123456789" };

    if (fopen_s(&TEXT, path, "r") != NULL)
    {
        cout << "Error";
    }

    else
    {
        while (!feof(TEXT))
        {
            c = fgetc(TEXT);

            for (int i = 0; i < strlen(letters); i++)
            {
                if (c == letters[i])
                {
                    dig++;
                }
            }

        }
    }

    return dig;
}