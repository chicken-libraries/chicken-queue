# 🐓 Chicken Queue

## About

* * *

Small lightweight package focused on providing an easy to use API for a classic queue.

## Tooling information

* * *

Targeted audience we are building for is Windows 10, MacOSX and Linux users. This
project uses [Meson](https://mesonbuild.com/) `0.56.0` and newer.

## Setup, Compile and Install

* * *

Using this package should be fairly simple just add the git wrap file in your subprojects
directory and include the dependency in your project.

```console
[wrap-git]
directory = chicken-queue
url = https://github.com/chicken-libraries/chicken-queue.git
revision = v0.1.0
```


The next step should be to add the package to your Meson project:

```meson
chicken_queue = subproject('chicken-queue')

executable('prog', files('main.c'),
    dependencies : [chicken_queue.get_variable('chicken_queue_dep')])

```

And finally we setup, and compile the project just like normal.

## Usage of this package

* * *

Here is a simple sample application that should get you up and running with using this
library as soon as possible but to learn more please view the API documentation thanks.

```c
#include <stdio.h>
#include <stdlib.h>
#include <chicken/queue.h>

//
// main is where all good examples start
//
int main(void)
{
    QueueOf *mQueue = chickenQueueCreate();
    if (chickenQueueItsEmpty(mQueue))
    {
        return EXIT_FAILURE;
    } // end if
    chickenQueuePush(mQueue, "hello");
    chickenQueuePush(mQueue, "crazy");
    chickenQueuePush(mQueue, "world");

    while (chickenQueueNotEmpty(mQueue))
    {
        printf("%s ", chickenQueuePeek(mQueue));
        chickenQueuePop(mQueue);
    } // end while
    chickenQueueErase(&mQueue);
    return EXIT_SUCCESS;
} // end of function main

```

## Contact the developer

* * *

You can contact me with either of these methods.

-   linkedin: [michael-brockus](https://www.linkedin.com/in/michael-brockus-1009a1174/)
-   reddit: [MichaelBrockus](https://www.reddit.com/user/MichaelBrockus)
-   gmail: [michaelbrockus@gmail.com](mailto:michaelbrockus@gmail.com).
