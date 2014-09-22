gulp   = require 'gulp'

# Dependencies
coffee = require 'gulp-coffee'
compass = require 'gulp-compass'

##### Build the files
gulp.task 'coffee', ->
  gulp.src('./src/app.coffee')
  .pipe(coffee(
    bare: true
  )).pipe(gulp.dest('./public/'))

gulp.task 'compass', ->
  gulp.src('./src/styles/*.scss')
  .pipe(compass(
    project: "."
    css: "public/styles/"
    sass: "src/styles/"
  ))
  .pipe(gulp.dest('./public/styles'))

gulp.task 'build', ->
