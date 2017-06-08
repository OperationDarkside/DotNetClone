# ProjectDNC
The purpose of this project is to provide basic classes and functionality to make code more readable. Due to restrictions of C++ there are some modifications. In the future there may be non-dotnet classes.

**CAUTION**: This code is in an experimental state

Motivation:
C++ is not the programming language I learned from the start. So coming from C# and Java I had problems reading C++ Code.
I'm aware, that the .NET Framework is available for C++, but the code then is neither native nor cross-plattform anymore.
A short web search didn't show any noticable open-source solutions, that could offer the functionality of .NET.
So I started this little side-project to bring the comfort of .NET to native C++.

As mentioned above, I am not an experienced C++ developer, so the code is not optimized or anything.

However, you are very welcome to check the code and point out bugs/impovements :-)
If you want to contribute, message me on Twitter


**Serialization**

Registering class members:

```C++
class TestDataClass: public Serializable {...

TestDataClass::TestDataClass() {
	Object& f1 = this->field1;
	Object& f2 = this->field2;
	Object& f3 = this->field3;

	this->name = "TestDataClass";
	this->attributes.Add(SerializableAttribute(String("Field1"), f1));
	this->attributes.Add(SerializableAttribute(String("Field2"), f2));
	this->attributes.Add(SerializableAttribute(String("Field3"), f3));
}

String xmlString = testClass.ToXml();
```

**MySql**

Executing a query:

```C++
DataTable memTable;

MySqlConnection connection(String("SERVER=127.0.0.1:3306;DATABASE=test;UID=root;PASSWORD="));

connection.Open();

MySqlCommand command(String("SELECT * FROM test WHERE ID = ?"), &connection);
command.Parameters().Add(MySqlParameter(MySqlDbTypes::LONG, 3));

MySqlDataAdapter adapt(command);
adapt.Fill(memTable);

connection.Close();
```

**String**

Joining a list:

```C++
dnc::Collections::Generic::List<String> listStrings;
listStrings.Add("Hallo");
listStrings.Add("Welt");
listStrings.Add("Noob");

String joined_string = String::Join(" ", listStrings);
// "Hallo Welt Noob"
```

**Type**

Polymorphic Type Checking:

```C++
Object* tmp_o = new String();
bool istype = Type::isType<Object, String>(tmp_o);
```


Frameworks:
- MySql C API - Installed

Maintainer:
Sebastian Greis

Twitter:
https://twitter.com/OpDarkside or the Hashtag #ProjectDNC

Youtube:
Video documentation about this and my other frameworks:
https://www.youtube.com/channel/UCBcbGguXSzkj7ocZMEIFnxw
