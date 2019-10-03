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

Note, you will need libpulsar (for linking) and libpulsar-dev (for C++
client header files, for compiling) installed first. For both, the Gem
currently targets version 2.4.1. If your libpulsar is older, it will
fail to compile. If it is newer, it _might_ compile is not guaranteed.

## Usage

Example:

```ruby
# have these in your shell with appropriate values
# export PULSAR_BROKER_URI=pulsar://your-pulsar-broker:6651
# export PULSAR_CERT_PATH=/path/to/your/pulsar-ca.pem
# export PULSAR_AUTH_TOKEN=your-auth-token

# create client using values from environment
client = Pulsar::Client.from_environment

# produce a message on the "hello-world" topic in the "namespace"
# namespace of the "tenant" tenant
topic = "tenant/namespace/topic"
producer = client.create_producer(topic)
producer.send("Hello, world!")

# consumer that message from the topic with an exclusive subscription
# named "hello-consumer"
subscription = "hello-consumer"
consumer = client.subscribe(topic, subscription)
consumer.listen do |message|
  puts message
  break
end
```

(more documentation coming; see TODO.md)

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
https://github.com/apache/pulsar-client-ruby or
https://github.com/instructure/pulsar-client-ruby.
