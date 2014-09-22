module.exports = (config) ->
  config.set
    basePath: '../'
    frameworks: ['jasmine']
    files: [
      'public/vendor.js'
      'public/app.js'
      'src/components/angular-mocks/angular-mocks.js'
      'tests/specs/**/*.coffee'
    ]
    preprocessors:
      '**/*.coffee': ['coffee']
    reporters: ['progress']
    port: 8081
    colors: yes
    loglevel: config.LOG_DEBUG
    autowatch: no
    browsers: ["PhantomJS"]
    captureTimeout: 20000
    singleRun: yes
    reportSlowerThan: 500
