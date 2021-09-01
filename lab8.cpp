#include <iostream>
#include <fstream>

// метод для разделения строки на подстроки с указанным разделителем,
// по умолчанию разделитель -- пробел
// но вообще это рил жоская залупа, ибо функция возвращает массив
// а именно массив через указатель. пиздец, по-другому и не скажешь
// (вообще, тут прикол в том, что в плюсах функция не может вернуть массив,
//  как и принять его в качестве своего аргумента,
//  а только указатель на его место в памяти, поэтому здесь и далее
//  используется эта всратая звёздочка)
std::string *split(std::string str, char separator, int size)
{
    std::string *arr = new std::string[size];
    // врЕменная переменная, хранящая в себе подстроку
    std::string temp = "";

    int j = 0;
    // цикл пробегается по строке, ищет, является ли символ разделителем
    for (int i = 0; i < (int)str.size(); i++)
    {
        // если нет -- то программа вносит символ в подстроку
        if (str[i] != separator)
        {
            temp += str[i];
        }
        // иначе -- записывает подстроку в возвращаемый массив
        else
        {
            arr[j] = temp;
            j++;
            temp = "";
        }
    }
    return arr;
}

// функция, которая находит количество вхождений определённого символа в строку
int find_all_entries(std::string str, char separator)
{
    int count = 0;
    // тыц-тыц-тыц по всем символам строки
    for (int i = 0; i < (int)str.size(); i++)
    {
        // суть такая же, как и в функции split
        if (str[i] == separator)
        {
            count++;
        }
    }
    return count;
}

// нахождение самого длинного слова
std::string find_longest_word(std::string *strings, int size)
{
    // создаётся тупа пустая строка никакой длины
    std::string longest_word = "";
    // пробегается по всем строкам массива
    for (int i = 0; i < size; i++)
    {
        if (strings[i].length() > longest_word.length())
        {
            longest_word = strings[i];
        }
    }
    return longest_word;
}

// чтение из файла
std::string read_from_file(std::string filename)
{
    std::string line;
    std::string text;
    std::ifstream myfile(filename);
    if (myfile.is_open())
    {
        int i = 0;
        while (std::getline(myfile, line))
        {
            // здесь оч всратая хрень с этим + " \n", но если этого не сделать,
            // то перестанет нормально работать функция split
            text += line + " \n";
        }
        myfile.close();
    }
    else
    {
        std::cout << "Невозможно открыть файл";
    }
    return text;
}

// запись в файл, ну тут рили всё просто
void write_to_file(std::string filename, std::string *data, int size)
{
    std::ofstream file;
    file.open(filename);

    for (int i = 0; i < size; i++)
    {
        file << data[i] << '\n';
    }

    file.close();
}

int main()
{
    // эта '*' опять-таки для того, чтобы можно было ебануть в переменную
    // массив, который создаёт функция split
    std::string *lines;
    std::string *words;

    std::string text = read_from_file("input.txt");
    int size = find_all_entries(text, '\n');
    lines = split(text, '\n', size);

    std::string longest_words[size];
    for (int i = 0; i < size; i++)
    {
        int size_of_string = find_all_entries(lines[i], ' ');
        words = split(lines[i], ' ', size_of_string);
        longest_words[i] = find_longest_word(words, size_of_string);
    }

    std::string filename;
    std::cout << "Введите название файла, в который будет записываться информация: ";
    std::cin >> filename;

    write_to_file(filename, longest_words, size);

    // тут удаление динамически созданных массивов, ибо плюсы сами не умеют,
    // у них лапки
    delete[] lines;
    delete[] words;
    return 0;
}
