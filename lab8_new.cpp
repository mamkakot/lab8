#include "lab8_new.h"

int main()
{
    std::string filename;
    std::vector<std::string> words;
    std::string max_length_words;
    std::string text = read_from_file("input.txt");

    words = split(text, ' ');

    auto max_word = *(std::max_element(words.begin(), words.end(), compare));

    for (auto word : words)
    {
        if (len(word) == len(max_word))
        {
            max_length_words += word + " ";
        }
    }

    std::cout << "введите название файла для записи: ";
    std::cin >> filename;
    write_to_file(filename, max_length_words);
    return 0;
}