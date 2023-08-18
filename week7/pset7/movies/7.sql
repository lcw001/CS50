SELECT title, rating
FROM movies
JOIN ratings on id = movie_id
WHERE year = '2010'
AND rating IS NOT NUll ORDER BY rating DESC, title;