Fri 31 Mar 18:16:07 UTC 2023

  Please see:

    git.show.2b0c845.log

Revert the flags if you wanted persistence - program is
configured (in this file) to compile to a no flashROM
image.

That way, another build of the same program can be resident
in flashROM, whereas the unstable work done recently is
uploaded via .UF2 - but does not get written to the storage
holding the (more stable) version that's resident in flashROM.

The commit is shown (in full) in the above cited logfile :)

