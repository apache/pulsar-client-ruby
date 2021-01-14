require "rspec/core/rake_task"
require "rake/extensiontask"

RSpec::Core::RakeTask.new(:spec)

task :default => [:compile, :spec]

Rake::ExtensionTask.new "bindings" do |ext|
  ext.lib_dir = "lib/pulsar"
end
