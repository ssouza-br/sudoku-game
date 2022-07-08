-- Keep a log of any SQL queries you execute as you solve the mystery.

-- checking crimes on 288/07/2021 at Humphrey Street
    -- SELECT * FROM crime_scene_reports WHERE day=28 AND month=07 AND year=2021 AND street='Humphrey Street'
    -- +-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    -- | id  | year | month | day |     street      |                                                                                                       description                                                                                                        |
    -- +-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    -- | 295 | 2021 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
    -- | 297 | 2021 | 7     | 28  | Humphrey Street | Littering took place at 16:36. No known witnesses.                                                                                                                                                                       |
    -- +-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

-- cheking interviews
    -- SELECT * FROM interviews WHERE day=28 AND month=07 AND year=2021 AND transcript LIKE "%bakery%"
    -- +-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    -- | id  |  name   | year | month | day |                                                                                                                                                     transcript                                                                                                                                                      |
    -- +-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    -- | 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
    -- | 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
    -- | 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
    -- +-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

--check first interview -> security camera
    -- SELECT * FROM bakery_security_logs WHERE day=28 AND month=07 AND year=2021 AND activity='exit' AND hour=10
    -- +-----+------+-------+-----+------+--------+----------+---------------+
    -- | id  | year | month | day | hour | minute | activity | license_plate |
    -- +-----+------+-------+-----+------+--------+----------+---------------+
    -- | 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
    -- | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
    -- | 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
    -- | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
    -- | 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
    -- | 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
    -- | 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
    -- | 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
    -- | 268 | 2021 | 7     | 28  | 10   | 35     | exit     | 1106N58       |
    -- +-----+------+-------+-----+------+--------+----------+---------------+

    --name of people on parking lot
    -- SELECT  id, name FROM people WHERE license_plate in
    -- (SELECT license_plate FROM bakery_security_logs WHERE day=28 AND month=07 AND year=2021 AND activity='exit' AND hour=10)

    -- +--------+---------+
    -- |   id   |  name   |
    -- +--------+---------+
    -- | 221103 | Vanessa |
    -- | 243696 | Barry   |
    -- | 396669 | Iman    |
    -- | 398010 | Sofia   |
    -- | 449774 | Taylor  |
    -- | 467400 | Luca    |
    -- | 514354 | Diana   |
    -- | 560886 | Kelsey  |
    -- | 686048 | Bruce   |
    -- +--------+---------+


--check second interview -> atm_transactions
    -- SELECT * FROM atm_transactions WHERE day=28 AND month=07 AND year=2021 AND atm_location LIKE "%Legget%" AND transaction_type='withdraw'
    -- +-----+----------------+------+-------+-----+----------------+------------------+--------+
    -- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
    -- +-----+----------------+------+-------+-----+----------------+------------------+--------+
    -- | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
    -- | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
    -- | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
    -- | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
    -- | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
    -- | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
    -- | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
    -- | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
    -- +-----+----------------+------+-------+-----+----------------+------------------+--------+

    --name of people withdraw money
    -- SELECT id, name FROM people WHERE id IN

    -- (SELECT person_id from bank_accounts where account_number in
    -- (SELECT account_number FROM atm_transactions WHERE day=28 AND month=07 AND
    -- year=2021 AND atm_location LIKE "%Legget%" AND transaction_type='withdraw')) order by name ASC
    -- +--------+---------+
    -- |   id   |  name   |
    -- +--------+---------+
    -- | 438727 | Benista |
    -- | 458378 | Brooke  |
    -- | 686048 | Bruce   |
    -- | 514354 | Diana   |
    -- | 396669 | Iman    |
    -- | 395717 | Kenny   |
    -- | 467400 | Luca    |
    -- | 449774 | Taylor  |
    -- +--------+---------+

--check third interview -> flights
    -- SELECT * FROM flights WHERE day=29 AND month=07 AND year=2021
    -- +----+-------------------+------------------------+------+-------+-----+------+--------+
    -- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
    -- +----+-------------------+------------------------+------+-------+-----+------+--------+
    -- | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
    -- | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
    -- | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
    -- | 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
    -- | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
    -- +----+-------------------+------------------------+------+-------+-----+------+--------+

    --check third interview -> flights -> passengers
    -- SELECT id, name from people where passport_number in

    -- (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE day=29 AND month=07 AND year=2021)) order by name ASC

    -- +--------+-----------+
    -- |   id   |   name    |
    -- +--------+-----------+
    -- | 325548 | Brandon   |
    -- | 458378 | Brooke    |
    -- | 686048 | Bruce     |
    -- | 423393 | Carol     |
    -- | 769190 | Charles   |
    -- | 952462 | Christian |
    -- | 750165 | Daniel    |
    -- | 447494 | Dennis    |
    -- | 514354 | Diana     |
    -- | 953679 | Doris     |
    -- | 757606 | Douglas   |
    -- | 651714 | Edward    |
    -- | 788213 | Emily     |
    -- | 682850 | Ethan     |
    -- | 788911 | Gloria    |
    -- | 210641 | Heather   |
    -- | 753885 | Jennifer  |
    -- | 677698 | John      |
    -- | 210245 | Jordan    |
    -- | 809265 | Jose      |
    -- | 560886 | Kelsey    |
    -- | 395717 | Kenny     |
    -- | 253397 | Kristina  |
    -- | 251693 | Larry     |
    -- | 467400 | Luca      |
    -- | 354903 | Marilyn   |
    -- | 619074 | Matthew   |
    -- | 626361 | Melissa   |
    -- | 542503 | Michael   |
    -- | 205082 | Pamela    |
    -- | 341739 | Rebecca   |
    -- | 710572 | Richard   |
    -- | 398010 | Sofia     |
    -- | 745650 | Sophia    |
    -- | 676919 | Steven    |
    -- | 449774 | Taylor    |
    -- | 660982 | Thomas    |
    -- +--------+-----------+

---CREATE INTERSECT BETWEEN WITHDRAW LIST AND PASSENGERS:

    -- SELECT id, name FROM people WHERE id IN

    -- (SELECT person_id from bank_accounts where account_number in
    -- (SELECT account_number FROM atm_transactions WHERE day=28 AND month=07 AND
    -- year=2021 AND atm_location LIKE "%Legget%" AND transaction_type='withdraw'))

    -- INTERSECT SELECT id, name from people where passport_number in

    -- (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE day=29 AND month=07 AND year=2021))

    -- +--------+--------+
    -- |   id   |  name  |
    -- +--------+--------+
    -- | 395717 | Kenny  |
    -- | 449774 | Taylor |
    -- | 458378 | Brooke |
    -- | 467400 | Luca   |
    -- | 514354 | Diana  |
    -- | 686048 | Bruce  |
    -- +--------+--------+

--check third interview -> phone_calls
    -- SELECT * FROM phone_calls WHERE day=28 AND month=07 AND year=2021 AND duration<=60
    -- +-----+----------------+----------------+------+-------+-----+----------+
    -- | id  |     caller     |    receiver    | year | month | day | duration |
    -- +-----+----------------+----------------+------+-------+-----+----------+
    -- | 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       |
    -- | 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36       |
    -- | 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
    -- | 234 | (609) 555-5876 | (389) 555-5198 | 2021 | 7     | 28  | 60       |
    -- | 251 | (499) 555-9472 | (717) 555-1342 | 2021 | 7     | 28  | 50       |
    -- | 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
    -- | 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
    -- | 261 | (031) 555-6622 | (910) 555-3251 | 2021 | 7     | 28  | 38       |
    -- | 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       |
    -- | 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54       |
    -- +-----+----------------+----------------+------+-------+-----+----------+

--check third interview -> people from caller phone number
    -- SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day=28 AND month=07 AND year=2021 AND duration<=60)
    --check license_plate with security camera -> stolen car
    -- +--------+---------+----------------+-----------------+---------------+
    -- |   id   |  name   |  phone_number  | passport_number | license_plate |
    -- +--------+---------+----------------+-----------------+---------------+
    -- | 395717 | Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       |
    -- | 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
    -- | 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       |
    -- | 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       |
    -- | 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
    -- | 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
    -- | 561160 | Kathryn | (609) 555-5876 | 6121106406      | 4ZY7I8T       |
    -- | 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
    -- | 907148 | Carina  | (031) 555-6622 | 9628244268      | Q12B3Z3       |
    -- +--------+---------+----------------+-----------------+---------------+



--check license plate caller
-- SELECT  id, name FROM people WHERE license_plate in

-- (SELECT license_plate FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day=28 AND month=07 AND year=2021 AND duration<=60)

-- INTERSECT

-- SELECT license_plate FROM bakery_security_logs WHERE day=28 AND month=07 AND year=2021 AND activity='exit' AND hour=10)

-- +--------+--------+
-- |   id   |  name  |
-- +--------+--------+
-- | 398010 | Sofia  |
-- | 449774 | Taylor |
-- | 514354 | Diana  |
-- | 560886 | Kelsey |
-- | 686048 | Bruce  |
-- +--------+--------+


---SACARAM E SÃO PASSAGEIROS
    -- +--------+--------+
    -- |   id   |  name  |
    -- +--------+--------+
    -- | 395717 | Kenny  |
    -- | 449774 | Taylor |
    -- | 458378 | Brooke |
    -- | 467400 | Luca   |
    -- | 514354 | Diana  |
    -- | 686048 | Bruce  |
    -- +--------+--------+

---LIGARAM E SAIRAM DO ESTACIONAMENTO
    -- +--------+--------+
    -- |   id   |  name  |
    -- +--------+--------+
    -- | 398010 | Sofia  |
    -- | 449774 | Taylor |
    -- | 514354 | Diana  |
    -- | 560886 | Kelsey |
    -- | 686048 | Bruce  |
    -- +--------+--------+




    -- List1 - Name of people on parking lot
    -- SELECT  id, name FROM people WHERE license_plate in
    -- (SELECT license_plate FROM bakery_security_logs WHERE day=28 AND month=07 AND year=2021 AND activity='exit' AND hour=10)

    -- +--------+---------+
    -- |   id   |  name   |
    -- +--------+---------+
    -- | 221103 | Vanessa |
    -- | 243696 | Barry   |
    -- | 396669 | Iman    |
    -- | 398010 | Sofia   |
    -- | 449774 | Taylor  |
    -- | 467400 | Luca    |
    -- | 514354 | Diana   |
    -- | 560886 | Kelsey  |
    -- | 686048 | Bruce   |
    -- +--------+---------+