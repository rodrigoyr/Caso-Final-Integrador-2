#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Ejercicio.h"
#include "Ejercicio2.h"
#include "Ejercicio3.h"
#include "Ejercicio4.h"
#include "Ejercicio5.h"
#include "Ejercicio6.h"
#include "Ejercicio7.h"
#include "Ejercicio8.h"
#include "Ejercicio9.h"
#include "Ejercicio10.h"
#include "Ejercicio11.h"
#include "Ejercicio12.h"
#include "Ejercicio13.h"
#include "Ejercicio14.h"
#include "Ejercicio15.h"
#include "Ejercicio16.h"
#include "Ejercicio17.h"
#include "Ejercicio18.h"
#include "Ejercicio19.h"
#include "Ejercicio20.h"
#include "Ejercicio21.h"
#include "Ejercicio22.h"
#include "Ejercicio23.h"
#include "Ejercicio24.h"
#include "Ejercicio25.h"
#include "Ejercicio26.h"
#include "Ejercicio27.h"
#include "Ejercicio28.h"
#include "Ejercicio29.h"
#include "Ejercicio30.h"
#include "Ejercicio31.h"
#include "Ejercicio32.h"
#include "Ejercicio33.h"
#include "Ejercicio34.h"
#include "Ejercicio35.h"
#include "Ejercicio36.h"
#include "Ejercicio37.h"
#include "Ejercicio38.h"
#include "Ejercicio39.h"
#include "Ejercicio40.h"
#include "Ejercicio41.h"
#include "Ejercicio42.h"
#include "Ejercicio43.h"
#include "Ejercicio44.h"
#include "Ejercicio45.h"
#include "Ejercicio46.h"
#include "Ejercicio47.h"
#include "Ejercicio48.h"
#include "Ejercicio49.h"
#include "Ejercicio50.h"
#include "Ejercicio51.h"
#include "Ejercicio52.h"
#include "Ejercicio53.h"
#include "Ejercicio54.h"
#include "Ejercicio55.h"
#include "Ejercicio56.h"
#include "Ejercicio57.h"
#include "Ejercicio58.h"
#include "Ejercicio59.h"
#include "Ejercicio60.h"
#include "Ej
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <cstdio>

using namespace std;

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado

void load_script(const char* filename, bool show_script = false)
{
    string script;
    FILE* f = nullptr;
    try
    {
        f = fopen(filename, "rb");
        if (!f)
        {
            cerr << "error de apertura de " << filename << endl;
            return;
        }

        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0)
        {
            buf[c] = 0;
            script.append(buf);
        }
        fclose(f);
        f = nullptr;

        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (...)
    {
        cerr << "error durante la lectura del archivo" << endl;
        if(f)
            fclose(f);
    }
}

void load_script()
{
    char filename[500];
    printf("Archivo: ");
    scanf("%499s", filename);
    load_script(filename, true);
}