SELECT title
FROM movies
Join stars on stars.movie_id = movies.id
Join people on people.id = stars.person_id
WHERE name = 'Johnny Depp'
AND movies.title in(
    SELECT movies.title
    FROM people
    JOIN stars ON people.id = stars.person_id
    JOIN movies ON stars.movie_id = movies.id
    WHERE people.name = 'Helena Bonham Carter'
    );