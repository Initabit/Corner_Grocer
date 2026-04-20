# Corner_Grocer
SNHU Portfolio 
# Project Three: Corner Grocer Item Tracker
**Developer:** David Anderson  
**Date:** April 20, 2026  
**Course:** CS210 – Programming Languages  

---

## Project Reflection

### 1. Summarize the project and what problem it was solving.
This C++ application analyzes an ingested file for purchase logs to help identify buying trends. It automates the counting process to provide data for produce counts and purchasing history.

### 2. What did you do particularly well?
I implemented a standardization layer that converts all input and search terms to lowercase for reliable, case-insensitive matching. This prevents capitalization errors from causing inaccurate frequency counts and improves the overall user experience. Also implemented controls to stop runtime erros and input validation for expected user entries.

### 3. Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
The program could be enhanced with deeper validation for the input text file to filter out non-item data or special characters. Could also implement better formatting for responses such as color coding or including historic data for comparisons. These changed would improve user feedback and usefulness for developing insight into purchasing trends.

### 4. Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
Coordinating case-insensitive map operations using the `<algorithm>` library’s `transform` function was the most challenging technical hurdle. However, viewing some examples on forums like W3 schools and other resources allowed for clarity. To support future projects, I am adding the C++ Standard Template Library (STL) documentation to my professional resource network.

### 5. What skills from this project will be particularly transferable to other projects or course work?
Developing object-oriented classes with public/private encapsulation and using maps for O(log n) data retrieval are essential, transferable skills. Implementing automatic data persistence through file I/O is a standard practice I will use in future development.

### 6. How did you make this program maintainable, readable, and adaptable?
The code uses a modular class design and descriptive naming conventions to keep logic clear and easy to modify. I also included detailed in-line documentation to explain the "why" behind specific implementation choices.