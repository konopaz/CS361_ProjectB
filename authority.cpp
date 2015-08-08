 vector<Location> createDatabase2() {
    vector<Location> database;
 
 Location auth1;
    auth1.name = "Portland EPA";
    auth1.telephone = "(503) 326-3250";
    auth1.streetAddress = "805 SW Broadway #500";
    auth1.city = "Portland";
    auth1.state = "OR";
    auth1.zip = "97205";
    database.push_back(auth1);

    Location auth2;
    auth2.name = "Western Ecology Center";
    auth2.telephone = "(503) 399-9969";
    auth2.streetAddress = "200 SW 35th St";
    auth2.city = "Corvallis";
    auth2.state = "OR";
    auth2.zip = "97333";
    database.push_back(auth2);


    Location auth3;
    auth3.name = "Seattle EPA";
    auth3.telephone = "(206) 553-1200";
    auth3.streetAddress = "1200 6th Ave";
    auth3.city = "Seattle";
    auth3.state = "WA";
    auth3.zip = "99101";
    database.push_back(auth3);

    Location auth4;
    auth4.name = "US EPA";
    auth4.telephone = "(408)562-9900";
    auth4.streetAddress = "61 Forsyth Street";
    auth4.city = "Atlanta";
    auth4.state = "GA";
    auth4.zip = "30303";
    database.push_back(auth4);

    Location auth5;
    auth5.name = "Corvallis Police Department";
    auth5.telephone = "(541) 766-6924";
    auth5.streetAddress = "180 NW 5th St";
    auth5.city = "Corvallis";
    auth5.state = "OR";
    auth5.zip = "97330";
    database.push_back(auth5);
	
	 Location auth6;
    auth6.name = "Benton County Natural Areas & Parks Department";
    auth6.telephone = "(541) 766-6781";
    auth6.streetAddress = "360 SW Avery Ave";
    auth6.city = "Corvallis";
    auth6.state = "OR";
    auth6.zip = "97333";
    database.push_back(auth6);
	
	
	return database;
}