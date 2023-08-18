SELECT name
FROM people
JOIN stars on people.id = person_id
JOIN movies on movies.id = movie_id
WHERE title = 'Toy Story';