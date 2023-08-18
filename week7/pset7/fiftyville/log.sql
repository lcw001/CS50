-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Read crime scene report
SELECT description
FROM crime_scene_reports
WHERE month = 7 and day = 28
and street like 'hum%';
--___________________________________
--| Theft of CS50 duck at 10:15am at the
--  Humphrey Street bakery. Interviews with three
--  witnesses.Each interview transcripts mentions the
--  bakery.
--___________________________________


-- search interview transcripts for bakery
SELECT transcript, name
FROM interviews
WHERE transcript
LIKE '%bakery%';
--___________________________________
--RUTH |  10:15-10:30, saw thief get into car.  look for cars on security footage
--EUGENE | I recognized thief. saw the thief withdrawing money from ATM on Leggett St.
--RAYMOND | thief called someone who talked to them for less than a minute while leaving bakery.
--          I heard thief say planning to take the earliest flight out tomorrow. The thief asked
--          the person to purchase the flight ticket.
--____________________________________

-- search baker security log for car leaving
SELECT name, activity, hour, minute
FROM people
JOIN bakery_security_logs on bakery_security_logs.license_plate = people.license_plate
WHERE month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 30
AND activity like 'exit';

--_________________________________________
--+---------+----------+------+--------+
--|  name   | activity | hour | minute |
--+---------+----------+------+--------+
--| Vanessa | exit     | 10   | 16     |
--| Bruce   | exit     | 10   | 18     |
--| Barry   | exit     | 10   | 18     |
--| Luca    | exit     | 10   | 19     |
--| Sofia   | exit     | 10   | 20     |
--| Iman    | exit     | 10   | 21     |
--| Diana   | exit     | 10   | 23     |
--| Kelsey  | exit     | 10   | 23     |
--+---------+----------+------+--------+
--____________________________________________
-- search atm_transactions 7/28 between 6am and 10:15am
SELECT atm_transactions.account_number, name
FROM atm_transactions
JOIN bank_accounts on bank_accounts.account_number = atm_transactions.account_number
JOIN people on bank_accounts.person_id = people.id
WHERE month = 7
AND day = 28
AND atm_location LIKE '%legget%'
AND transaction_type LIKE 'withdraw%'
ORDER BY name;

--______________________________________
--+----------------+---------+
--| account_number |  name   |
--+----------------+---------+
--| 81061156       | Benista |
--| 16153065       | Brooke  |
--| 49610011       | Bruce   | + exit
--| 26013199       | Diana   | + exit
--| 25506511       | Iman    | + exit
--| 28296815       | Kenny   |
--| 28500762       | Luca    | + exit
--| 76054385       | Taylor  |
--+----------------+---------+
--____________________________________

-- search phone log for calls made 7/28 duration <1m
SELECT people.name, caller, receiver
FROM phone_calls
JOIN people on phone_calls.caller = people.phone_number
WHERE month = 7
AND day = 28
AND duration < 60
ORDER BY name;

--_____________________________________
+---------+----------------+----------------+------------+
|  name   |     caller     |    receiver    |    name    |
+---------+----------------+----------------+------------+
| Benista | (338) 555-6650 | (704) 555-2131 | Anna       |
| Bruce   | (367) 555-5533 | (375) 555-8161 | Robin      | + atm, exit
| Carina  | (031) 555-6622 | (910) 555-3251 | Jacqeuline |
| Diana   | (770) 555-1861 | (725) 555-3243 | Philip     | + atm, exit
| Kelsey  | (499) 555-9472 | (892) 555-8872 | Larry      |
| Kelsey  | (499) 555-9472 | (717) 555-1342 | Melissa    |
| Kenny   | (826) 555-1652 | (066) 555-9701 | Doris      |
| Sofia   | (130) 555-0289 | (996) 555-8899 | Jack       |
| Taylor  | (286) 555-6063 | (676) 555-6554 | James      |
+---------+----------------+----------------+------------+

-- ORIGIN - check early (before noon) flights on 7/29
SELECT flights.id, abbreviation, city, hour, minute
FROM flights
JOIN airports on origin_airport_id = airports.id
WHERE hour < 12
AND month = 7
AND day = 29;

--___________________________________________________________________
--+----+--------------+------------+------+--------+
--| id | abbreviation |    city    | hour | minute |
--+----+--------------+------------+------+--------+
--| 36 | CSF          | Fiftyville | 8    | 20     |
--| 43 | CSF          | Fiftyville | 9    | 30     |
--+----+--------------+------------+------+--------+
--___________________________________________________________________

-- DESTINATION - identify destination city of early flights
SELECT flights.id, abbreviation, city, hour, minute
FROM flights
JOIN airports on destination_airport_id = airports.id
WHERE hour < 12
AND month = 7
AND day = 29;

--_________________________________________________
--+----+--------------+---------------+------+--------+
--| id | abbreviation |     city      | hour | minute |
--+----+--------------+---------------+------+--------+
--| 36 | LGA          | New York City | 8    | 20     |
--| 43 | ORD          | Chicago       | 9    | 30     |
--+----+--------------+---------------+------+--------+
--_____________________________________________________

-- look for passenger(s) on 7/29 to LGA or ORD

SELECT people.name, flights.id
FROM people
JOIN passengers on people.passport_number = passengers.passport_number
JOIN flights on flights.id = passengers.flight_id
WHERE flights.id = 36 OR flights.id = 43
AND month = 7
AND day =29
ORDER BY flights.id, name;

--_______________________________________
--+---------+----+
--|  name   | id |
--+---------+----+
--| Bruce   | 36 | + atm, exit, caller
--| Doris   | 36 |
--| Edward  | 36 |
--| Kelsey  | 36 |
--| Kenny   | 36 |
--| Luca    | 36 |
--| Sofia   | 36 |
--| Taylor  | 36 |
--| Carol   | 43 |
--| Daniel  | 43 |
--| Heather | 43 |
--| Marilyn | 43 |
--| Rebecca | 43 |
--| Sophia  | 43 |
--+---------+----+
--______________________________________________


-- Bruce, Diana, Inman, Luca at ATM on Legget St. 7/28
-- Bruce, Diana, Inman, Luca exited bakery 7/28 10:15-10:30
-- Bruce called Robin 7/28 duration <60s
-- Early flight on 7/29 to LGA (NYC) at 8:20
-- Bruce on that flight