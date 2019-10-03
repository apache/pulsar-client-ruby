lib = File.expand_path("../lib", __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require "pulsar/client/version"

Gem::Specification.new do |spec|
  spec.name          = "pulsar-client"
  spec.version       = Pulsar::Client::VERSION
  spec.date          = "2019-10-03"
  spec.summary       = "Apache Pulsar Ruby Client"
  spec.description   = "Apache Pulsar Ruby Client"
  spec.authors       = ["Jacob Fugal"]
  spec.email         = ["lukfugl@gmail.com"]
  # once merged upstream to apache, we'll rename the homepage
  spec.homepage      = "https://github.com/instructure/pulsar-client-ruby"
  spec.license       = "Apache License 2.0"

  spec.files         = `git ls-files -z`.split("\x0").reject do |f|
    f.match(%r{^(test|spec|features)/})
  end
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }

  spec.extensions    = ["ext/bindings/extconf.rb"]

  spec.add_development_dependency "bundler", "~> 1.16"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "rspec", "~> 3.0"

  spec.add_dependency "rake-compiler"
  spec.add_dependency "rice"
end
