SELECT DISTINCT(name) FROM people JOIN stars ON people.id=stars.person_id JOIN movies ON stars.movie_id=movies.id
WHERE NOT people.name='Kevin Bacon' AND movies.title IN

(SELECT title FROM movies JOIN stars ON movies.id=stars.movie_id JOIN people ON stars.person_id=people.id
WHERE (people.name='Kevin Bacon') AND (people.birth=1958)) ORDER BY movies.title ASC

-- SELECT name FROM people JOIN stars ON people.id=stars.person_id JOIN movies ON stars.person_id=movies.id
-- WHERE movies.title='Diner'

-- SELECT name FROM people JOIN stars ON people.id=stars.person_id JOIN movies ON stars.movie_id=movies.id WHERE movies.title='Diner';
