SELECT name FROM people as p JOIN stars as s ON p.id=s.person_id JOIN movies as m ON p.id=m.id WHERE m.title='Toy Story';



Example query:
select column_names
from Student_detail as s join Attendance_details as a on
s.s_id = a.s_id join Batch_details as b on
s.s_id = b.s_id;






-- SELECT name FROM people WHERE id=(SELECT person_id FROM stars JOIN movies on stars.movie_id=movies.id WHERE movies.title='Toy Story')
-- SELECT person_id FROM stars JOIN movies on stars.movie_id=movies.id WHERE movies.title='Toy Story'

-- SELECT name FROM people WHERE id=(SELECT person_id FROM stars JOIN movies on stars.movie_id=movies.id WHERE movies.title='Toy Story')