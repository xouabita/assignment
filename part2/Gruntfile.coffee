module.exports = (grunt) ->
  grunt.initConfig
    basePath: "."
    sources: "<%= basePath %>/src"
    output: "<%= basePath %>/public"
    components: "<%= sources %>/components"
    port: 3001

    coffee:
      sources:
        src: "<%= sources %>/app.coffee"
        dest: "<%= output %>/app.js"

    compass:
      dist:
        options:
          sassDir: "<%= sources %>/styles"
          cssDir: "<%= output %>/styles"

    copy:
      html:
        src: "<%= sources %>/index.html"
        dest: "<%= output %>/index.html"
      assets:
        files: [
          expand: true
          cwd: "<%= sources %>/assets/"
          src: ["**"]
          dest: "<%= output %>/assets/"
        ]

    concat:
      options:
        separator: ";"
      vendor:
        src: [
          "<%= components %>/angular/angular.min.js"
        ]
        dest: "<%= output %>/vendor.js"

    clean:
      output:
        files: [
          expand: true
          cwd: "<%= output %>"
          src: "[**]"
        ]

    watch:
      options:
        livereload: true
      scripts:
        files: ["<%= sources %>/app.coffee"]
        tasks: ["coffee:sources"]
      compass:
        files: ["<%= sources %>/styles/**/*.scss"]
        tasks: ["compass"]
      html:
        files: ['<%= sources %>/index.html']
        tasks: ["copy:html"]
      assets:
        files: ["<% sources %>/assets/**/*.*"]
        tasks: ["copy:assets"]

    express:
      all:
        options:
          port: port
          hostname: "0.0.0.0"
          bases: ["<%= output %>"]
          livereload: true

    open:
      all:
        path: 'http://localhost:<%= port %>'

  require('load-grunt-tasks') grunt

  grunt.registerTask "build", [
    "clean:output"
    "copy:assets"
    "copy:html"
    "concat:vendor"
    "coffee:sources"
    "compass"
  ]
