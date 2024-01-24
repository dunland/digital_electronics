su## Overview

from [bytebytego: Understanding Database Types](https://blog.bytebytego.com/p/understanding-database-types)
![[SQLvsNoSQL.png]]

![[typesOfDatabases.png]]

![[databaseComparison.png]]

## Standard Commands

- [`CREATE TABLE`](https://www.codecademy.com/resources/docs/sql/commands/create-table?page_ref=catalog) creates a new table.
- [`INSERT INTO`](https://www.codecademy.com/resources/docs/sql/commands/insert-into?page_ref=catalog) adds a new row to a table.
- [`SELECT`](https://www.codecademy.com/resources/docs/sql/commands/select?page_ref=catalog) queries data from a table.
- [`ALTER TABLE`](https://www.codecademy.com/resources/docs/sql/commands/alter-table?page_ref=catalog) changes an existing table.
- [`UPDATE`](https://www.codecademy.com/resources/docs/sql/commands/update?page_ref=catalog) edits a row in a table.
- [`DELETE FROM`](https://www.codecademy.com/resources/docs/sql/commands/delete?page_ref=catalog) deletes rows from a table.

## PostgreSQL

### installation:

[codeacademy: Installing PostgreSQL](https://www.codecademy.com/paths/design-databases-with-postgresql/tracks/what-is-a-database/modules/using-postgresql-on-your-own-computer/articles/installing-and-using-postgresql-locally)
[postgresqltutorial.com: installation](https://www.postgresqltutorial.com/postgresql-getting-started/install-postgresql-linux/)
- **Start Server:** `sudo pg_ctlcluster 12 main start` → "specified cluster '12 main' does not exist." → `sudo apt-get install postgresql-12` ✓
### GUI: Postbird / PgAdmin / ...

[PostgreSQL configuration using Docker, Postbird and Sequelize](https://matheus-beck.github.io/blog/docker/postgresql/postbird/sequelize/2019/09/11/configuring-postgres-docker-postbird-sequelize.html) ✓
> Unable to find image 'postgres:latest' locally
> docker: Error response from daemon: driver failed programming external connectivity on endpoint database (22e1aa60ec3511c4736046c6fd96da98d4fdd8a6d41f166842537298f387dfd5): Error starting userland proxy: listen tcp4 0.0.0.0:5432: bind: address already in use.

``` bash
fuser 5432/tcp
lsof -i4
lsof -i :5432 # postgres 2209 postgres    6u  IPv4  25264      0t0  TCP localhost:postgresql (LISTEN)
kill 2209
docker run --name movieList -e POSTGRES_PASSWORD=docker -p 5432:5432 -d postgres
docker ps  # success!
```

Now in **Postbird**:
- Host: localhost
- Port: 5432
- username: postgres
- password: docker
- Database: --EMPTY--
### CLI: psql
- `sudo -u postgres psql` to start
- `\q` to quit


## SQLite
[codeacademy: Installing SQLite](https://www.codecademy.com/courses/learn-sql/articles/what-is-sqlite)
