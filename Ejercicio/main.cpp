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
        cerr << "Error de apertura de " << filename << endl;
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
    cout << "Archivo: ";
    cin.getline(filename, sizeof(filename));
    load_script(filename, true);
}

int main()
{
    load_script();
    return 0;
}
