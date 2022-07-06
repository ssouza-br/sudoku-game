-- Keep a log of any SQL queries you execute as you solve the mystery.

-- checking crimes on 288/07/2021 at Humphrey Street
-- SELECT * FROM crime_scene_reports WHERE day=28 AND month=07 AND year=2021 AND street='Humphrey Street'

-- cheking interviews
-- SELECT * FROM interviews WHERE day=28 AND month=07 AND year=2021 AND transcript LIKE "%bakery%"

--check first interview -> security camera
SELECT * FROM interviews WHERE day=28 AND month=07 AND year=2021 AND transcript LIKE "%bakery%"