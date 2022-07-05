SELECT name FROM people JOIN stars ON people.id=stars.person_id JOIN movies ON people.id=movies.id WHERE movies.title='Toy Story';
-- SELECT name FROM people WHERE id=(SELECT person_id FROM stars JOIN movies on stars.movie_id=movies.id WHERE movies.title='Toy Story')
-- SELECT person_id FROM stars JOIN movies on stars.movie_id=movies.id WHERE movies.title='Toy Story'

-- SELECT name FROM people WHERE id=(SELECT person_id FROM stars JOIN movies on stars.movie_id=movies.id WHERE movies.title='Toy Story')