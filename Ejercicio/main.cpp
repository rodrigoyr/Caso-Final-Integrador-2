#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox
{
    void new_text() { /*...*/ }
    void set_text(const string &text) { cout << text << endl; }
};

static ConsoleBox *consoleBox = new ConsoleBox;

void load_script(const char *filename, bool show_script = false)
{
    ifstream file(filename, ios::binary);

    if (!file.is_open())
    {
        cerr << "Error: El archivo '" << filename << "' no existe." << endl;
        return;
    }

    try
    {
        string script((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        file.close();

        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }

        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (const exception &e)
    {
        cerr << "Error durante la lectura del archivo: " << e.what() << endl;
        file.close();
    }
}

void load_script()
{
    string filename;
    cout << "Ingrese el nombre del archivo: ";
    cin >> filename;

    if (filename.empty())
    {
        cerr << "Error: No se proporcionó un nombre de archivo válido." << endl;
        return;
    }

    load_script(filename.c_str(), true);
}

int main()
{
    load_script();
    return 0;
}
