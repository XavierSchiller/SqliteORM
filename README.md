# SQLite3 ORM 

### Why?

Made as an intresting insight into the database engine of sqlite3. As such, this is not supported by anyone, including the developer of this project. You are free to use this in any project. For further information, look up ORM and sqlite3.

### To Implement.

The things I need to do:

- Implement Data Retrival. (Partially Done, I need to provide an interface for accessing that)

- Make allowances for special types in sqlite3 like blob, text, etc.

- Make way for multiple Queries to be executed at once.

- Handle Journal mode.

- Handle Transactions. 

- Write quick start methods to jumpstart project.

- Make it cross platform (Windows in particular, Cmake behaves badly.)

- Write a better Cmake file to support many tests.

- Write unit tests. ~~What are unit tests?~~

- Make multithreading supported. 

- Query Creator? (This one is out of bounds at the moment. Just a thought.)

- Make it fast. (Secondary goal)

- Provide Node and Python Bindings.

- Make it self contained.

### What can I do to this? 

Anything, really. LICENSE can be checked for additional details.

# Things to note:

- Uses [any lite](https://github.com/martinmoene/any-lite) inplace of std::any(C++17) to preserve C++11 compatibility.