
import csv
from cs50 import SQL

#Open db file
db = SQL("sqlite:///student.db")

#Open CSV file
with open("students.csv") as file:

    #Create reader
    reader = csv.DictReader(file)
    counter = 0

    # Skip header row
    #next(reader)

    #Iterate over CSV file and insert into db
    for row in reader:
        
        id = db.execute("INSERT INTO students (student_name) VALUES(?)", row["student_name"]),
        #print(row["student_name"])

        id = db.execute("INSERT INTO houses (house, head) VALUES(?, ?)", row["house"], row["head"])
        #print(row["house"], row["head"])


