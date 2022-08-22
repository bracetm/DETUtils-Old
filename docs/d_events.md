# d_events.inc
Pawn Events - Provides the new `@event` callback which is now a replacement for `forward` and `public`.

[Go back to the home page](../README.md)

## How to start to use?

- Now using `@event` you can create local and global events on a file level. The difference between local and global events is similar to static and global variables and functions! Local event usage is limited to only **one** file. You declare it like this:

### Local Events

```pawn
// file1.pwn
@event(.type = LOCAL) LocalEvent()
{
    print("Debug");
    return 1;
}
```

- This event can now be used only in `file1.pwn`. You can use it by calling it using `CallEvent`.

```pawn
// file1.pwn
CallEvent(LocalEvent, "LocalEvent" , "");
```

- After you start the compiled script, you should see this in the console:

```
Debug
```

- But if you try to do this:

```pawn
// It was previously used only in file1.pwn
// file2.pwn
CallEvent(LocalEvent, "LocalEvent" , "");
```

- Your code will get compiled, but you won't see any messages in the console which is not the case with global events.

### Global Events

```pawn
// file1.pwn
@event(.type = GLOBAL) GlobalEvent()
{
    print("Debug2");
    return 1;
}
```

- This is a global event, and its usage isn't limited to a single file.

```pawn
CallEvent(GlobalEvent, "GlobalEvent", "");
```
- Using this in any file will work and will print the `Debug2` messages in the console.