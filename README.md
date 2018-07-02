# 7DaysWorldEditor
Not working yet. Far far from it.

## Code writing guidelines:

### File structure rules:

#### Header (.h) files

##### Include order:
0. pragma once
1. Base class
2. Internal files (within the project)
3. External files (libraries, etc)
4. Standard libraries (<string>, <memory>, etc)
5. Defines
6. Forward declarations
7. Defines
8. Enums limited to this file

All of the groups should be separated with one row and items withing group should be sorted alphabetically.
Each group should be separated by a empty line.
There should be an absolute minimum number of includes in the header files, and forward declarations should be used instead when possible.
No source files should EVER be included.

##### Class structure:
1. Public members
2. Protected members
3. Private members

###### Structure of each group (sets):
1. Constants
2. Static variables
3. Variables
4. Constructors
5. Destructors
6. Static methods
7. Methods

Ordering within a set should be such that it makes most logical sense.
Logically cohesive members within a set can be separated by an empty line.
Each group should be separated by an empty line.

Const keyword should be applied wherever applicable to improve code separation (i.e. prevent methods that shouldn't mutate the state of the object to do just that).

#### Source (.cpp) files:

##### Include order:
1. Corresponding header file
2. Same rules as the ordering of includes in the header file

All includes not present in the corresponding header file, but required to independently compile the source file should be included.
Only exception to this rules are derived classes which can, but don't have to, include header files included by the base class.
No source files should EVER be included.

##### Ordering of class members:
The order of the members should mirror the one in the corresponding header file.
There should be an empty line between each member definition. Exception to this rule are members with no bodies.


### Formatting rules:

Formatting that should be used is stored in the "\VS Settings\C++ Text Editor Settings.vssettings" file.
In order to use it, open Tools > Import and Export Settings menu in VS and follow the instructions.
You will be able to store your current settings to which you will be able to revert to at a later time.

