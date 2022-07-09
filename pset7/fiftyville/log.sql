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

    -- List1 - Name of people on parking lot
    -- SELECT  id, name FROM people WHERE license_plate in
    -- (SELECT license_plate FROM bakery_security_logs WHERE day=28 AND month=07 AND year=2021 AND activity='exit' AND hour=10 AND minute<=25)

    -- +--------+---------+
    -- |   id   |  name   |
    -- +--------+---------+
    -- | 221103 | Vanessa |
    -- | 243696 | Barry   |
    -- | 396669 | Iman    |
    -- | 398010 | Sofia   |
    -- | 467400 | Luca    |
    -- | 514354 | Diana   |
    -- | 560886 | Kelsey  |
    -- | 686048 | Bruce   |
    -- +--------+---------+
    -- List2 - name of people withdraw money
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

    -- List3 - phone call caller
    -- SELECT id, name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day=28 AND month=07 AND year=2021 AND duration<=60)
    -- +--------+---------+
    -- |   id   |  name   |
    -- +--------+---------+
    -- | 395717 | Kenny   |
    -- | 398010 | Sofia   |
    -- | 438727 | Benista |
    -- | 449774 | Taylor  |
    -- | 514354 | Diana   |
    -- | 560886 | Kelsey  |
    -- | 561160 | Kathryn |
    -- | 686048 | Bruce   |
    -- | 907148 | Carina  |
    -- +--------+---------+

    -- List4 - passengers
    -- SELECT id, name from people where passport_number in

    -- (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE day=29 AND month=07 AND year=2021 ANd id=36)) order by name ASC

    -- +--------+--------+
    -- |   id   |  name  |
    -- +--------+--------+
    -- | 686048 | Bruce  |
    -- | 953679 | Doris  |
    -- | 651714 | Edward |
    -- | 560886 | Kelsey |
    -- | 395717 | Kenny  |
    -- | 467400 | Luca   |
    -- | 398010 | Sofia  |
    -- | 449774 | Taylor |
    -- +--------+--------+


--INTERSECT LIST1, LIST2, LIST3 AND LIST4

    -- SELECT  id, name FROM people WHERE license_plate in
    -- (SELECT license_plate FROM bakery_security_logs WHERE day=28 AND month=07 AND year=2021 AND activity='exit' AND hour=10 AND minute<=25)

    -- INTERSECT

    -- SELECT id, name FROM people WHERE id IN
    -- (SELECT person_id from bank_accounts where account_number in
    -- (SELECT account_number FROM atm_transactions WHERE day=28 AND month=07 AND
    -- year=2021 AND atm_location LIKE "%Legget%" AND transaction_type='withdraw'))

    -- INTERSECT

    -- SELECT id, name FROM people WHERE phone_number IN
    -- (SELECT caller FROM phone_calls WHERE day=28 AND month=07 AND year=2021 AND duration<=60)

    -- INTERSECT

    -- SELECT id, name from people where passport_number in
    -- (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE day=29 AND month=07 AND year=2021 and id=36))

    -- +--------+-------+
    -- |   id   | name  |
    -- +--------+-------+
    -- | 686048 | Bruce |
    -- +--------+-------+

--Bruce receiver
    -- SELECT name FROM people WHERE phone_number IN

    -- (SELECT receiver FROM phone_calls WHERE id IN

    -- (SELECT id FROM phone_calls WHERE day=28 AND month=07 AND year=2021 AND duration<=60 AND caller in
    -- (SELECT phone_number FROM people WHERE name='Bruce')))

    -- +-------+
    -- | name  |
    -- +-------+
    -- | Robin |
    -- +-------+

--check destination
-- select city from airports where id in (select destination_airport_id from flights where id=36);

    -- +---------------+
    -- |     city      |
    -- +---------------+
    -- | New York City |
    -- +---------------+
