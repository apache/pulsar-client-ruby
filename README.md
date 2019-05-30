# Apache Pulsar Ruby client

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'pulsar-client'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install pulsar-client

## Usage

TBD

## Development

If your ruby is not already compiled with `--enable-shared`, you'll need
to rebuild it. Example for rbenv:

```
CONFIGURE_OPTS="--enable-shared" rbenv install <your ruby version>
```

If you don't already have them installed, you need libpulsar and
automake for the compilation and linking to work. Example with brew:

```
brew install libpulsar automake
```

Next, run `bin/setup` to install dependencies -- Rice in particular.
Once that successfully completes, you can `rake compile` to build the
extension. It is then ready to use locally.

You can run `bin/console` for an interactive prompt that will
allow you to experiment. You can also run `rake spec` to run the tests.

To install this gem onto your local machine, run `bundle exec rake
install`.

## Contributing

Bug reports and pull requests are welcome on GitHub at
https://github.com/apache/pulsar-client-ruby.
