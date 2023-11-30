#include <iostream>
#include <memory> // uso de unique_ptr
#include <vector>
#include <string>
#include <fstream>

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

unique_ptr<ConsoleBox> consoleBox = make_unique<ConsoleBox>(); // uso de unique_ptr

void load_script(const char* filename, bool show_script = false)
{
    string script;
    ifstream file(filename); // uso de ifstream en lugar de FILE*

    try
    {
        if (!file.is_open())
        {
            cerr << "Error de apertura de " << filename << endl;
            return;
        }

        char buf[4001];
        while (file.read(buf, sizeof(buf) - 1))
        {
            buf[file.gcount()] = 0;
            script.append(buf);
        }

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
        cerr << "Error durante la lectura del archivo" << endl;
    }
}

void load_script()
{
    string filename;
    cout << "Archivo: ";
    cin >> filename;
    load_script(filename.c_str(), true);
    int uninitialized_variable;  // Error: variable no inicializada
    cout << uninitialized_variable << endl; // Se utiliza la variable no inicializada
}

int main()
{
    load_script(); // Ejemplo de uso
    return 0;
}

