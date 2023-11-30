#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

class ConsoleBox
{
public:
    void display_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado

void load_script(const char* filename, bool show_script = false)
{
    string script;
    ifstream file(filename, ios::in);

    if (!file.is_open())
    {
        cerr << "Error: El archivo '" << filename << "' no existe." << endl;
        return;
    }

    try
    {
        string line;
        while (getline(file, line))
        {
            script += line + "\n";
        }

        file.close();

        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }

        consoleBox->display_text(script);
    }
    catch (const exception& e)
    {
        cerr << "Error durante la lectura del archivo: " << e.what() << endl;
        file.close();
    }
}

void load_script()
{
    char filename[500];
    cout << "Ingrese el nombre del archivo: ";
    cin.getline(filename, sizeof(filename));

    if (filename[0] == '\0')
    {
        cerr << "Error: No se proporcionó un nombre de archivo válido." << endl;
        return;
    }

    load_script(filename, true);
}

int main()
{
    load_script();
    return 0;
}
