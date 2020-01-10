# SQLite3 ORM 

### Why?

Made as an intresting insight into the database engine of sqlite3. As such, this is not supported by anyone, including the developer of this project. You are free to use this in any project. For further information, look up ORM and sqlite3.

### Things Done:
- Data Retrival based on a table format (row col format);
  - Need to provide number of rows and cols.
  - Fetches an Entire Record (1 to N)

- Query Binding
  - Very simple Binding, doesn't take care of inserting quotes around anything.

- Transactions are done.
  - Need to improve on this, since the transactional model is reliant on the user calling a function.

- One Query, Multiple Queries Execution is done as well.

- Error Handling is done through one single exception, sqlite_error, that can be caught and thrown.

- Self Contained(Mostly, considering, I still depend on sqlite3 libraries.)

### To Implement.

The things I need to do:

- Clean up
  - Code looks Positively ugly. Fix that.

- Tests
  - Add Coverage Tests and automate those tests.

- Cross Platform
  - It's automatically Cross platform, But make sure that things compile smoothly.

- Advanced SQLite Features:
  - Journal Mode
  - Typing
  - Extend SQLite with stored Procedures.

- Transactional Model

- Things to consider:
  - Documentation (Not a word.)
  - Clear examples. 

- To Be researched:
  - MultiThreading

- Things to do in the future once this project is stable:
  - Node Bindings (JS Bindings Really.)
  - Python Bindings.
  - Spin my own version of Any?

### Performance

It is about the same as the raw sqlite3 performanace. Only a few ms on top of it per 1000 transactions due to function calls. 

### What can I do to this? 

Anything, really. LICENSE can be checked for additional details.

# Things to note:

