#include <iostream>
#include <memory>
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
    void new_text() { /*...*/ }
    void set_text(const string& text) { cout << text << endl; }
};

vector<unique_ptr<ConsoleBox>> consoleBoxes;

void load_script(const string& filename, bool show_script = false)
{
    string script;
    ifstream file(filename);

    try
    {
        if (!file.is_open())
        {
            throw ios_base::failure("Error de apertura de " + filename);
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

        consoleBoxes.emplace_back(make_unique<ConsoleBox>());
        auto& currentConsoleBox = *consoleBoxes.back();
        currentConsoleBox.new_text();
        currentConsoleBox.set_text(script);
    }
    catch (const ios_base::failure& e)
    {
        cerr << "Error durante la lectura del archivo: " << e.what() << endl;
    }
    catch (const exception& e)
    {
        cerr << "Error desconocido: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Error inesperado durante la lectura del archivo" << endl;
    }
}

void load_script()
{
    string filename;
    cout << "Introduce el nombre del archivo: ";
    cin >> filename;
    load_script(filename, true);
}

int main()
{
    load_script();
    return 0;
}
