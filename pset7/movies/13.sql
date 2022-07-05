SELECT title FROM movies JOIN stars ON movies.id=stars.movie_id JOIN people ON stars.person_id=people.id
WHERE (people.name='Kevin Bacon')


SELECT name FROM people JOIN stars ON people.id=stars.person_id JOIN movies ON stars.person_id=movie.id
WHERE (people.name='Helena Bonham Carter');
