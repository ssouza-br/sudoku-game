-- SELECT DISTINCT(name) , movies.title, stars.person_id FROM people JOIN stars ON people.id=stars.person_id JOIN movies ON stars.person_id=movies.id
-- WHERE movies.title IN

-- SELECT title FROM movies JOIN stars ON movies.id=stars.movie_id JOIN people ON stars.person_id=people.id
-- WHERE (people.name='Kevin Bacon') AND (people.birth=1958)

SELECT name FROM people JOIN stars ON people.id=stars.person_id JOIN movies ON stars.person_id=movies.id
WHERE movies.title='Diner'
