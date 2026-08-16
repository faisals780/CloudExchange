# Practical Coding Practice — HTML, CSS, JavaScript & OOP
*(Hands-on tasks to write and run in VS Code — not theory questions)*

> Create one file/folder per section (e.g. `html-practice/`, `css-practice/`, `js-practice/`, `oop-practice/`) and knock these out one by one. Each task is something you actually build/run, not something you answer in words.

---

## 1. HTML Practice

1. Create a basic HTML5 boilerplate page with proper `<!DOCTYPE>`, `<head>`, and `<body>` tags, and set the page title to your name.
2. Add headings `<h1>` through `<h6>` to a page, one of each, and see how browser default sizing differs.
3. Create a paragraph of text and make one word **bold**, one word *italic*, and one word both.
4. Build an ordered list of your top 5 favorite movies/shows.
5. Build a nested unordered list (a list with a sub-list inside one of its items).
6. Insert an image into your page using the `<img>` tag with proper `alt` text.
7. Create a hyperlink that opens in a new tab and points to any website.
8. Build a simple table with 3 columns and 3 rows, including a `<thead>` and `<tbody>`.
9. Create a basic contact form with fields for name, email, and message, plus a submit button.
10. Add a dropdown (`<select>`) with at least 4 options to your form.
11. Use `<div>` and `<span>` to wrap and group content, and give them `id`/`class` attributes.
12. Embed a YouTube video using an `<iframe>`.
13. Create a page with a `<header>`, `<nav>`, `<main>`, and `<footer>` using semantic tags.

---

## 2. CSS Practice

1. Link an external CSS file to your HTML page and change the background color of the `<body>`.
2. Change the font family, size, and color of all paragraph text.
3. Use a class selector to style only specific elements (not all of them).
4. Use an id selector to style one unique element differently from the rest.
5. Create a `<div>` and give it a fixed width, height, background color, and border.
6. Add padding and margin to a box and observe the difference between the two visually.
7. Center a `<div>` horizontally on the page using margin auto.
8. Center a `<div>` both horizontally and vertically using Flexbox.
9. Create a navbar with 4 links laid out horizontally using Flexbox.
10. Build a 3-column layout using CSS Grid.
11. Change the color and text-decoration of a link on hover using `:hover`.
12. Give a box rounded corners and a subtle box-shadow.
13. Make an image responsive so it resizes with the browser window (`max-width: 100%`).
14. Create a simple button and style its default, hover, and active states differently.

---

## 3. JavaScript Practice (Keep it Simple)

1. Write a script that shows an alert box saying "Hello, World!" when the page loads.
2. Declare a variable with your name and print it to the console using `console.log()`.
3. Write a function that takes two numbers and returns their sum, then log the result.
4. Create a button in HTML that, when clicked, changes the text of a paragraph using JavaScript.
5. Write a script that changes the background color of the page when a button is clicked.
6. Store 5 fruit names in an array and print each one using a `for` loop.
7. Write a simple `if-else` statement that checks if a number is even or odd and logs the result.
8. Create an input box and a button — when clicked, show the input value in an alert.
9. Write a function that takes your age and returns whether you are a "minor" or "adult".
10. Use `document.getElementById()` to select an element and change its inner text.
11. Create a simple counter: a number on the page that increases by 1 every time a button is clicked.
12. Write a `while` loop that logs numbers from 1 to 10.

---

## 4. OOP Practice (C++)

1. Create a class `Student` with private data members `name` and `age`, and public getter/setter functions.
2. Write a constructor for the `Student` class that initializes `name` and `age` when an object is created.
3. Add a destructor to the `Student` class that prints a message when an object is destroyed.
4. Create a class `Rectangle` with `length` and `width`, and a member function `area()` that returns the area.
5. Demonstrate **encapsulation** by making the data members of a class private and only accessible through public methods.
6. Create a base class `Animal` with a method `sound()`, and a derived class `Dog` that overrides `sound()` — demonstrate **inheritance**.
7. Create two classes with a method of the same name (e.g. `area()` in `Circle` and `Square`) to demonstrate **compile-time polymorphism** using function overloading.
8. Use a `virtual` function in a base class and override it in a derived class to demonstrate **run-time polymorphism**.
9. Create an abstract class using a pure virtual function, and implement it in a derived class.
10. Create a class with a `static` member variable that keeps count of how many objects have been created.
11. Overload the `+` operator for a class `Point` (with `x` and `y`) so two `Point` objects can be added directly.
12. Demonstrate **multiple inheritance** by creating a class that inherits from two different base classes.
13. Create a `Bank Account` class where the balance can only be modified through `deposit()` and `withdraw()` functions, never directly.

---

## Tips for Practicing
- Actually **write and run** each snippet in VS Code — don't just read them.
- For HTML/CSS, open the file directly in your browser (Live Server extension helps a lot).
- For JS, use the browser console (`F12`) alongside your code to check outputs.
- For OOP/C++, compile and run each one (`g++ file.cpp -o file && ./file`) to see real behavior.
- Once comfortable, try combining tasks (e.g., build a small form with HTML+CSS+JS together).
