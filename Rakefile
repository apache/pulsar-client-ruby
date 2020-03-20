require "rspec/core/rake_task"
require "rake/extensiontask"

RSpec::Core::RakeTask.new(:spec)

task :default => :spec

Rake::ExtensionTask.new "bindings" do |ext|
  ext.lib_dir = "lib/pulsar"
end
