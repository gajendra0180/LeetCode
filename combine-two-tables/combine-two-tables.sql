select Person.firstName,Person.lastName,Address.city,Address.state from
Person LEFT OUTER JOIN Address  ON Person.PersonId = Address.PersonId;