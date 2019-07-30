# Confirm Licensing and Copyright

Currently, the repository LICENSE file states APL 2.0, reiterated in the
Ruby source files. The NOTICE file attributes Copyright to the ASF. Get
approval for this from Instructure OSC.

Aside: The uncompiled C++ in the ext/bindings/ directory are also
distributed, to be compiled on the user's machine during gem install.
Should these then also have license information per file, as the Ruby
files do?

# README Detail

The README has very minimal information on installing and building
locally right now. It needs to be fleshed out more. In particular, usage
of the library, specifically around significant divergences from the C++
code (e.g. `ClientConfiguration#authentication_token=` and
`Consumer#listen`)

# Write Some Specs

# Code TODOs

* `producer.schema`
* `consumer.negative_acknowledge`
