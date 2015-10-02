A tool to attack the blurry tiger128,3 hash [found in Destiny](https://www.reddit.com/r/DestinyTheGame/comments/3k7ele/spoiler_hidden_hash_puzzle_in_the_mine_area_of/cuwep2b).  
Because the target hash may not be 100% correct, the tool simply outputs how many nibbles differ between the current hash and the target hash.

Reads candidate words from STDIN, outputs current best match to STDOUT.

**Example:**

    $ ./destiny_tiger < english_tiny.txt
    Diff: 31; Str: <a>; Hash: 77befbef2e7ef8ab2ec8f93bf587a7fc
    Diff: 30; Str: <aardvark>; Hash: 7bba4f2b495ae5c7a80ae3e4c343f3fd
    Diff: 29; Str: <abaci>; Hash: e027eaae268cf04bc9821c32769970e1
    Diff: 28; Str: <abase>; Hash: 209f1ea0e8d14569f10ca30b2033861b
    Diff: 27; Str: <abc>; Hash: 2aab1484e8c158f2bfb8c5ff41b57a52
    Diff: 25; Str: <abnegate>; Hash: 1cdda07902465fe4ed3bbd462d396877
    Diff: 24; Str: <carthage>; Hash: c549a876d45a1e42e9f66432cf468ab9
    Diff: 23; Str: <draftsmen>; Hash: eedbe5c6ea2967728463ec3b13ea9017
    Input ended after 27414 lines
