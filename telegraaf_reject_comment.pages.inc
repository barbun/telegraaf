<?php

/**
 * @file
 * User page callbacks for the telegraaf reject comment module.
 */

/**
 * Menu callback; rejects specified comment.
 *
 * @param integer $cid
 *   A comment identifier.
 */
function telegraaf_reject_comment_callback($cid) {
  if (!isset($_GET['token']) || !drupal_valid_token($_GET['token'], "comment/$cid/reject")) {
    return MENU_ACCESS_DENIED;
  }
  if ($comment = comment_load($cid)) {
    $comment->status = COMMENT_REJECTED;
    comment_save($comment);

    drupal_set_message(t('Comment rejected.'));
    drupal_goto('node/' . $comment->nid);
  }
  return MENU_NOT_FOUND;
}
