import csv
import sys

db = {}
dict_seq = {}


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) == 3:
        database = sys.argv[1]
        sequence = sys.argv[2]
    else:
        print("Missing arguments")

    # TODO: Read database file into a variable
    with open(database, "r") as dbfile:
        database_reader = csv.DictReader(dbfile)
        headers = database_reader.fieldnames
        for row in database_reader:
            db[row["name"]] = {}
            for i in headers[1:]:
                db[row["name"]][i] = row[i]

    # TODO: Read DNA sequence file into a variable
    with open(sequence, "r") as sqfile:
        sequence_reader = csv.reader(sqfile)
        # headers = sequence_reader.fieldnames
        for row in sequence_reader:
            seq = row

    # TODO: Find longest match of each STR in DNA sequence
    for i in headers[1:]:
        dict_seq[i] = longest_match(seq[0], i)

    # TODO: Check database for matching profiles
    for name in db:
        success_count = 0
        for subseq in db[name]:
            if int(db[name][subseq]) == dict_seq[subseq]:
                success_count += 1
        if success_count == len(headers[1:]):
            print(name)
            return 0
    print("No match")
    return


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


main()
