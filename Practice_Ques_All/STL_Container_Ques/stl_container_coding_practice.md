# C++ STL Container Practice — Coding Edition
*(Hands-on tasks to write and run in VS Code — not theory questions)*

> Create one `.cpp` file per container (e.g. `vector_practice.cpp`) and write actual working code for each task. Compile and run each one to confirm the output (`g++ file.cpp -o file && ./file`).

---

## 1. `vector`

1. Declare a vector of integers, insert 5 elements using `push_back()`, and print all of them.
2. Take 5 integers as input from the user and store them in a vector, then print the sum of all elements.
3. Print a vector's elements in reverse order using a loop.
4. Write code that removes the last element of a vector and prints the vector before and after.
5. Insert an element at the 3rd position of a vector using `insert()` and print the result.
6. Erase a specific element (by value) from a vector and print the updated vector.
7. Sort a vector of integers in ascending order using `sort()` from `<algorithm>` and print it.
8. Find and print the maximum and minimum element of a vector using `*max_element()` and `*min_element()`.
9. Create a vector of strings, and print only the strings that start with a specific letter.
10. Create a 2D vector (vector of vectors) of size 3x3, fill it with numbers, and print it like a matrix.
11. Write code that copies one vector into another and modifies only the copy — prove the original is unaffected.

---

## 2. `list`

1. Declare a list of integers, insert 5 elements using `push_back()`, and print them using an iterator.
2. Insert an element at the front and back of a list, then print the full list.
3. Remove the first and last elements of a list and print the result.
4. Write code to reverse a list using the built-in `reverse()` function.
5. Sort a list of integers using the built-in `sort()` member function and print it.
6. Remove all occurrences of a specific value from a list using `remove()`.
7. Insert an element in the middle of a list using an iterator and `insert()`.
8. Write code to merge two sorted lists into one using the built-in `merge()` function.
9. Traverse a list from back to front using a reverse iterator.
10. Take 5 names as input, store them in a list, and print only names longer than 4 characters.

---

## 3. `deque`

1. Declare a deque of integers, insert elements at both the front and back, and print the final deque.
2. Take 5 integers as input and store them in a deque, then print them in reverse.
3. Remove one element from the front and one from the back, and print before/after.
4. Access and print the 3rd element of a deque using `[]`.
5. Write code that sorts a deque using `sort()` from `<algorithm>`.
6. Use a deque to simulate adding people to a queue from the back and removing from the front.
7. Print the front and back elements of a deque without removing them.
8. Create a deque of strings and print only the ones with more than 5 characters.
9. Copy a deque into a vector and print both to confirm the values match.
10. Clear a deque completely and confirm it's empty by checking its size.

---

## 4. `set`

1. Declare a set of integers, insert 6 values (including duplicates), and print the set — confirm duplicates and sorting.
2. Take 5 integers as input, insert them into a set, and print them in sorted order.
3. Check if a specific value exists in a set using `find()` and print "Found" or "Not Found".
4. Erase a specific value from a set and print the set before/after.
5. Insert 5 strings into a set and print them — observe alphabetical ordering.
6. Print the smallest and largest elements of a set using `begin()` and `rbegin()`.
7. Write code to count how many elements in a set are greater than a given number.
8. Create two sets and write code to print their common elements (intersection) using `set_intersection()`.
9. Insert values into a `multiset` and show that duplicates are allowed and grouped together.
10. Remove all elements from a set that are even numbers.

---

## 5. `unordered_set`

1. Declare an `unordered_set` of integers, insert 6 values, and print them — observe the (non-sorted) order.
2. Take 5 strings as input and store them in an `unordered_set`, then check if a specific string exists using `find()`.
3. Insert a duplicate value into an `unordered_set` and prove only one copy is stored (print the size).
4. Erase a specific element from an `unordered_set` and print before/after.
5. Count how many buckets an `unordered_set` is using via `bucket_count()`.
6. Write code that inserts 100000 random integers into both a `set` and `unordered_set`, and roughly compares insertion time using `<chrono>`.
7. Create an `unordered_set` of strings and iterate over it to print all values.
8. Convert a vector with duplicate values into an `unordered_set` to remove duplicates, then print the result.
9. Check the load factor of an `unordered_set` using `load_factor()`.
10. Write code to check if two `unordered_set`s have any common elements.

---

## 6. `map`

1. Declare a `map<string, int>` to store 5 names and ages, and print all key-value pairs.
2. Take a word and its meaning as input from the user 5 times, store in a map, and print them alphabetically by key.
3. Check if a specific key exists in a map using `find()`, and print "Exists" or "Doesn't Exist".
4. Update the value of an existing key in a map and print before/after.
5. Erase a specific key from a map and print the updated map.
6. Write a program to count the frequency of each character in a string using a `map<char, int>`.
7. Iterate through a map using a range-based for loop and print `key: value` pairs.
8. Access a key using `[]` that doesn't exist yet, and observe that it gets auto-inserted with a default value.
9. Create a `map<int, vector<string>>` and store multiple names under the same numeric key.
10. Print all key-value pairs of a map in reverse order using reverse iterators.
11. Create a `multimap<string, int>` where one key can map to multiple values, and print all values for a given key.

---

## 7. `unordered_map`

1. Declare an `unordered_map<string, int>` to store 5 names and marks, and print all pairs (observe non-sorted order).
2. Write a program to count word frequency in a sentence using `unordered_map<string, int>`.
3. Check if a specific key exists using `find()` and print the result.
4. Update the value for an existing key and print before/after.
5. Erase a key from an `unordered_map` and print the updated map.
6. Iterate through an `unordered_map` and print all key-value pairs.
7. Compare lookup speed between `map` and `unordered_map` for 100000 insertions using `<chrono>`.
8. Create an `unordered_map<char, int>` to count vowels in a string.
9. Use an `unordered_map<int, string>` to store roll numbers and names, then look up a name by roll number.
10. Check the number of buckets and load factor of an `unordered_map` using `bucket_count()` and `load_factor()`.

---

## 8. `stack`

1. Declare a stack of integers, push 5 elements, and print them by popping one by one.
2. Write a program to check if the top element of a stack equals a given value.
3. Push 5 elements onto a stack, then print the size before and after popping 2 elements.
4. Write a program to reverse a string using a stack.
5. Use a stack to check if a given string of brackets `()[]{}` is balanced.
6. Push elements from a vector onto a stack, then print them in reverse order by popping.
7. Write code to check if a stack is empty before popping (avoid runtime errors).
8. Implement a simple "undo" feature: push actions (as strings) onto a stack and pop the last one when "undo" is triggered.
9. Convert a decimal number to binary using a stack.
10. Print the top element of a stack without removing it, then pop and print again.

---

## 9. `queue`

1. Declare a queue of integers, push 5 elements, and print them by popping (dequeuing) one by one.
2. Write a program simulating a ticket counter: names enter a queue and are served (popped) one at a time.
3. Push 5 elements onto a queue and print the front and back elements without removing them.
4. Check if a queue is empty before popping, and print an appropriate message if it is.
5. Push elements from an array into a queue, then print the total count using `size()`.
6. Write a program that adds and removes elements from a queue based on user input in a loop (simulate a real queue system).
7. Use two stacks to implement a queue's `push` and `pop` behavior manually.
8. Push characters of a string one by one into a queue, then pop and print them to reconstruct the string.
9. Simulate a print queue: add 5 print jobs (strings) to a queue and process (print + remove) them one by one.
10. Write code that empties a queue completely and confirms it's empty using `empty()`.

---

## 10. `priority_queue`

1. Declare a `priority_queue<int>`, push 6 unsorted numbers, and pop them one by one to show they come out in descending order.
2. Create a min-heap version of `priority_queue<int>` using `greater<int>` and print elements in ascending order.
3. Push 5 elements onto a priority_queue and print just the top (maximum) element.
4. Write a program to find the 3 largest elements from a list of numbers using a `priority_queue`.
5. Push `pair<int, string>` values (priority, task name) into a priority_queue and process them by priority.
6. Simulate a hospital emergency room: patients with priority numbers get pushed into a priority_queue, and the most urgent patient is served first.
7. Push elements into both a max-heap and min-heap priority_queue and print both outputs side by side.
8. Write code to check if a priority_queue is empty before calling `top()` or `pop()`.
9. Create a priority_queue of strings and observe the (alphabetical, descending) order they pop out in.
10. Merge two arrays and print the top 3 smallest values using a min-heap `priority_queue`.

---

## 11. `pair`

1. Declare a `pair<int, string>`, initialize it, and print both elements.
2. Create a vector of pairs `vector<pair<int, string>>` storing roll numbers and names, and print them all.
3. Use `make_pair()` to create a pair and store it in a vector.
4. Sort a vector of pairs by the first element in ascending order using `sort()`.
5. Sort a vector of pairs by the second element instead of the first.
6. Create a `map<string, pair<int, int>>` storing a name mapped to (age, marks), and print all entries.
7. Swap the values of two pairs using the `swap()` function and print before/after.
8. Compare two pairs using `==` and `<` operators and print the result.
9. Create a pair of pairs `pair<pair<int,int>, string>` and access nested elements.
10. Write code that returns a pair from a function (e.g., min and max of an array) and prints both values in `main()`.

---

## Tips for Practicing
- Actually **compile and run** every snippet — reading code isn't the same as writing it.
- Use `cout` liberally to check the state of your container after every operation.
- Try re-doing a few tasks from memory a day later without looking back at your old code.
- Once comfortable, try combining containers (e.g., a `map<string, vector<int>>` or `unordered_map<int, priority_queue<int>>`).
