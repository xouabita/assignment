gulp   = require 'gulp'

# Dependencies
coffee  = require 'gulp-coffee'
compass = require 'gulp-compass'
concat  = require 'gulp-concat'

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

gulp.task 'copy', ->
  gulp.src("./src/index.html").pipe(gulp.dest("./public/"))

gulp.task 'concat', ->
  gulp.src([
    "./src/components/jquery/dist/jquery.js"
    "./src/components/angular/angular.js"
    "./src/components/ngInfiniteScroll/build/ng-infinite-scroll.js"
  ])
  .pipe(concat("vendor.js"))
  .pipe(gulp.dest("./public/"))

gulp.task 'build', ["coffee","concat","copy"]
