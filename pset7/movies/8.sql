SELECT name FROM people JOIN stars ON people.id=stars.person_id JOIN movies ON stars.person_id=movies.id WHERE movies.title='Toy Story';
