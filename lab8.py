def main():
    with open("input.txt") as input_file:
        data = input_file.read().split()

    max_len = max(len(x) for x in data)

    filename = input("Введите название файла для записи: ")
    with open(filename, "w") as output_file:
        for word in data:
            if len(word) == max_len:
                output_file.write(word + "\n")


if __name__ == "__main__":
    main()
