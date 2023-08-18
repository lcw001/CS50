from cs50 import get_string
def main():
    len = 0
    text = get_string("Text: ")
    letters = 0.0
    sentances = 0.0
    words = 1

    for x in text:
        if x.isalpha():
            letters += 1
        if (x == "." or x == "!" or x == "?"):
            sentances += 1
        elif x == ' ':
            words += 1

    num_letters = calc_grade(letters, sentances, words)
#    print(f"grade \n", grade)
    if num_letters < 1:
        num_letters = 1
        print(f"Before Grade {num_letters:.0f}")
    elif num_letters >= 16:
        num_letters = 16
        print(f"Grade {num_letters:.0f}+")
    else:
        print(f"Grade {num_letters:.0f}")

#  function to calculate grade level
def calc_grade(letters, sentances, words):
    L = (letters / words) * 100
    S = (sentances / words) * 100
    grade = 0.0588 * L - 0.296 * S - 15.8
    return grade

if __name__ == "__main__":
    main()
