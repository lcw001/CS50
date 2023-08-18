import csv
import sys


def main():

    # Check for command-line usage
    # Ensure correct usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py database_file text_file")
        # sys.exit(1)

    # Read database file into a variable
    # read teams into memory from csv file
    filename = sys.argv[1]
    with open(filename) as file:
        file_reader = csv.DictReader(file)
        DNAdatabase = [row for row in file_reader]

    # Read DNA sequence file into variable sequence
    # create variable for list
    TXTfile = ()
    # read teams into memory from csv file
    filename = sys.argv[2]
    TXTfile = open(filename, 'r')
    # read text file contents to sequence
    sequence = TXTfile.read()
    TXTfile.close()

    # Find longest match of each STR in DNA sequence
    # longest_sequence = longest_match(sequence, subsequence)
    STRcount = {}
    for key in DNAdatabase[0].keys():
        if key == 'name':
            continue
        STRcount[key] = longest_match(sequence, key)

    # Check database for matching profiles
    for row in DNAdatabase:
        match = True
        for key in row.keys():
            if key == 'name':
                continue
            if int(row[key]) != STRcount[key]:
                match = False
                break
        if match:
            print(row['name'])
            return
    print("No match.")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


if __name__ == "__main__":
    main()
