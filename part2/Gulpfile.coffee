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

#### Setup static server w/ livereload
embedlr    = require 'gulp-embedlr'
refresh    = require 'gulp-livereload'
lrserver   = require('tiny-lr')()
express    = require 'express'
livereload = require 'connect-livereload'

livereload_port = 35759
server_port     = 5000

server = express()
server.use(livereload(
  port: livereload_port
))
server.use express.static('./public')
server.all '/*', (req,res) ->
  res.sendFile('index.html', {root: "public"})

gulp.task 'serve', ->
  server.listen(server_port)
  lrserver.listen(livereload_port)
