# SQLite3 ORM 

### Why?

Made as an intresting insight into the database engine of sqlite3. As such, this is not supported by anyone, including the developer of this project. You are free to use this in any project. For further information, look up ORM and sqlite3.

### Things Done:
- Data Retrival based on a table format (row col format);
  - Need to provide number of rows and cols.

- Query Binding
  - Very simple Binding, doesn't take care of inserting quotes around anything.

- Transactions are done.
  - Need to improve on this, since the transactional model is reliant on the user calling a function.

- One Query, Multiple Queries Execution is done as well.

- Error Handling is done through one single exception, sqlite_error, that can be caught and thrown.



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