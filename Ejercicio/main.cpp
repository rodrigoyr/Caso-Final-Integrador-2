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
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado

void load_script(const char* filename, bool show_script = false)
{
    string script;
    ifstream file(filename, ios::binary);

    if (!file.is_open())
    {
        cerr << "Error de apertura de " << filename << endl;
        return;
    }

    try
    {
        file.seekg(0, ios::end);
        script.resize(file.tellg());
        file.seekg(0, ios::beg);
        file.read(&script[0], script.size());
        file.close();

        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }

        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (const exception& e)
    {
        cerr << "Error durante la lectura del archivo: " << e.what() << endl;
        file.close();
    }
}

void load_script()
{
    string filename;
    cout << "Archivo: ";
    cin >> filename;
    load_script(filename.c_str(), true);
}

int main()
{
    load_script();
    return 0;
}
